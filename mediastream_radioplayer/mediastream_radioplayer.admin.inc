<?php

/**
 * @file
 * Contains page callbacks for mediastream_radioplayer.
 */

/**
 * Creates/returns a form to configure the module settings.
 *
 * @param array $form
 *   A structured array containing the elements and properties of the form.
 * @param array $form_state
 *   An array that stores information about the form's current state
 *   during processing.
 *
 * @return array
 *   Form to config mediastream player module.
 */
function mediastream_radioplayer_configure($form, &$form_state) {
  $form = array();
  // URL with the streaming API jason.
  $form['mediastream_radioplayer_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Mediastre API URL'),
    '#description' => t('Paste here the API Url provided from Mediastre. Confirm with them if the API is a json object.'),
  // Meadiastream API.
    '#default_value' => variable_get('mediastream_radioplayer_url', ''),
    '#required' => TRUE,
  );
  // File selection form element.
  $form['mediastream_radioplayer_thumb'] = array(
    '#name' => 'radioplayer_default_img',
    '#type' => 'managed_file',
    '#title' => t('Upload Image - 100x100 px'),
    '#description' => t('Default image to display if the streaming data has no images.  Only *.gif, *.png, *.jpg, y *.jpeg allowed.'),
    '#default_value' => variable_get('mediastream_radioplayer_thumb', ''),
    '#upload_location' => 'public://media/image/',
    '#upload_validators' => array(
      'file_validate_is_image' => array(),
      'file_validate_extensions' => array('gif png jpg jpeg'),
      'file_validate_image_resolution' => array('500x500', '100x100'),
    ),
    '#required' => TRUE,
  );

  $form['#submit'][] = 'mediastream_radioplayer_form_submit';
  // Use system_settings_form() to automate saving configuration variables.
  return system_settings_form($form);
}

/**
 * Implements validation from the Form API.
 *
 * @param array $form
 *   A structured array containing the elements and properties of the form.
 * @param array $form_state
 *   An array that stores information about the form's current state
 *   during processing.
 */
function mediastream_radioplayer_configure_validate($form, &$form_state) {
  // Ensure URL is valid URL.
  if (!valid_url($form_state['values']['mediastream_radioplayer_url'], TRUE)) {
    form_set_error('url', t('The URL %url is invalid. Enter a fully-qualified URL, such as http://nowplaying.mediastre.am/api/station/*ID*/nowplaying', array('%url' => $form_state['values']['mediastream_radioplayer_url'])));
  }
  // Ensure URL is a valid Mediastre API url.
  $url = parse_url($form_state['values']['mediastream_radioplayer_url']);
  if ($url['host'] != 'nowplaying.mediastre.am') {
    form_set_error('url', t('The URL %url is not a valid Mediastre API url. Ask your meadia stream provider for a valid API url like: http://nowplaying.mediastre.am/api/station/*ID*/nowplaying', array('%url' => $form_state['values']['mediastream_radioplayer_url'])));
  }
  // Decode the JSON data && Ensure URL contains a valid JSON object.
  $url = $form_state['values']['mediastream_radioplayer_url'];
  if (json_last_error() !== JSON_ERROR_NONE) {
    form_set_error('url', t('The URL %url is not a valid Json Object. Ask your meadia stream provider for a valid API url holding a json object like: http://nowplaying.mediastre.am/api/station/*ID*/nowplaying. Otherwise this module is useless :(', array('%url' => $form_state['values']['mediastream_radioplayer_url'])));
  }

}

/**
 * Form submission handler for mediastream_radioplayer_thumb form.
 */
function mediastream_radioplayer_form_submit($form, $form_state) {
  if (!empty($form_state['values']['mediastream_radioplayer_thumb'])) {
    $file = file_load($form_state['values']['mediastream_radioplayer_thumb']);
    $block = block_load('mediastream_radioplayer', 'streaming_data');

    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'mediastream_radioplayer', 'streaming_data', $block->bid);
    variable_set('mediastream_radioplayer_thumb_fid', $file->fid);

  }
  else {
    drupal_set_message(t('No subiste ninguna imagen!'));
  }
}
