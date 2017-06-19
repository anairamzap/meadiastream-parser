## Mediastream Radioplayer parser Drupal module
This module integrates [Mediastre.am](http://mediastre.am) API with Drupal, allowing you to display the streaming data in a Drupal block.
Currently outputs the artist name and image, the song title and the name of the current _programa_ (programme name).

Here you can see an example - Block displaying streaming data:
![Example preview](player_preview.png?raw=true "Example Preview")


### Instructions to install module in Drupal
Nothing really fancy, just follow the common Drupal procedure to install/enable/configure modules:

1. Download the module and extract it in the modules directory

2. Enable the module in _yoursiteurl_/admin/modules
   OR if using drush:
   ```
   $ drush en mediastream_radioplayer
   ```

3. Configure the module settings in its config page _yoursiteurl_/admin/config/mediastream_radioplayer/settings

4. Place the block in the region you want to display the Radio player *Preview* going to Block configuration page _yoursiteurl_/admin/structure/block

5. Note that you can override module's template saving mediastream_radioplayer.tpl.php template in your theme's templates directory. Also, we provide a simple css file to add an initial styling (mstream-player.css).

Settings page Screenshot:
![Settings page](mediastream_radioplayer_settings.png?raw=true "Settings page Screenshot")


### Mediastream Radioplayer module docs

Mediastream Radioplayer module 'simply' parses a json object (retrieved from Mediastream), outputs the relevant content** into a drupal block in HTML, and adds an autoupdate function (using Javascript) to refresh the block contents every 20 seconds. This is to display the updated streaming data. 

**We collect the following fields: 
- song title
- artist name
- artist thumbnail
- programa

If you think we are missing important information that you want to display, please go ahead and add those into the mediastream_radioplayer_json_to_block and mediastream_radioplayer_block_view functions. If you are not a developer, you can send us your requests and wishes (only related to this module functionality please! :P ) to [contacto@anairamzap.com.ar](mailto:contacto@anairamzap.com.ar)

If you are a developer and want to extend and improve this module, please go ahead! Thare are a few @todo comments that would be lovely to get done :)


### Some more useful information
- The generated block will always have this ID: 'block-mediastream-radioplayer-streaming-data'. This info might be useful if you want to theme the generated block. For example, using a block template named `block--futurock-radioplayer--streaming-data.tpl.php`

- This module comes with a theming template (mediastream_radioplayer.tpl.php) that you can override in your theme's directory to modify the markup as desired.

- This module comes with a css file mstream-player.css which provides some initial basic styling. Feel free to override those in your own css file.

- Please take into account this module has an autorefresh function! Try not to add much data (like huge images) inside the module template as this will be reloaded every 20 seconds. Be nice with your server, don't stress it :)
