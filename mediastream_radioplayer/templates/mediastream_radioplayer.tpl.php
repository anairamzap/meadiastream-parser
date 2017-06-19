<?php
/**
 * @file
 * Returns HTML for the streaming data.
 *
 * Available variables:
 * $thumb - URL of the thumb image.
 *  If streaming data has no image, it will use the Default image set
 *  in the module config page.
 * $programa - String. Programa name from stream metatag.
 * $artist - String. Artist name from stream metatag.
 * $song - String. Song title from stream metatag.
 *
 * You can override this template in your theme :)
 * We also privide a basic css file to style initially.
 * @ingroup themeable
 */
?>

<span class="thumb">
  <img src="<?php print $thumb;?>" />
</span>

<span class="programa">
  <?php print $programa;?>
</span>

<span class="artist">
  <?php print $artist;?>
</span>

<span class="song">
  <?php print $song;?>
</span>
