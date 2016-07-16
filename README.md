## Mediastream Radioplayer parser Drupal module

### Instructions to install module in Drupal
Nothing really fancy, just follow the common Drupal procedure to install/enable/configure modules:

1. Download the module and extract it in the modules directory

2. Enable the module in _yoursiteurl_/admin/modules

3. Configure the module settings in its config page _yoursiteurl_/admin/mediastream_radioplayer/settings

4. Place the block in the region you want to display the Radio player Preview going to Block configuration page _yoursiteurl_/admin/structure/block

5. Note that you can override module's template saving mediastream_radioplayer.tpl.php template in your theme's templates directory :)


### Mediastream Radioplayer module docs

Mediastream Radioplayer module 'simply' parses a json object (retrieved from Mediastream), outputs the relevant content** into a drupal block in HTML, and adds an autoupdate function (using JS) to refresh the block contents every 2 seconds. This is to display the updated streaming data. 

**We are just using the following fields: 
- song title
- artist name
- artist image
- programa

If you think we are missing important information that you want to display, please go ahead and add those into the json_to_block and mediastream_radioplayer_block_view functions. If you are not a developer, you can send us your requests and wishes (only related to this module functionality please! :P ) to [contacto@anairamzap.com.ar](mailto:contacto@anairamzap.com.ar)

### Some more useful information
- The generated block will always have this ID: 'block-mediastream-radioplayer-streaming-data'. This info might be useful if you want to theme the generated block. For example, using a block template named `block--futurock-radioplayer--streaming-data.tpl.php`

- This module comes with a theming template (mediastream_radioplayer.tpl.php) that you can override in your theme's directory to modify the markup as desired.

- Please take into account the autorefresh function! Try not to add much data (like huge images) inside the module template as this will be reloaded every 2 seconds. Be nice with your server, don't stress it :)
