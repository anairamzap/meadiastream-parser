<?php
/**
 * @file
 * Returns HTML for the streaming data.
 *
 * Available variables:
 *  $thumb - URL of the thumb image. 
 *  If no image came from the stream, it will use the Default one set in the module config page.
 *  $programa - String. Programa name from stream metatag.
 *  $artist - String. Artist name from stream metatag.
 *  $song - String. Song title from stream metatag.
 *
 *  You can override this template in your theme :)
 *  @ingroup themeable
 */
?>

  <?//php dsm(get_defined_vars()); ?>
  <span class="thumb">
    <img src="<?php print $thumb;?>" />
  </span>

  <span class="programa">
  <?php echo $programa;?>
  </span>

  <span class="artist">
  <?php echo $artist;?>
  </span>

  <span class="song">
  <?php echo $song;?>
  </span>
