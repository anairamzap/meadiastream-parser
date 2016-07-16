(function($){
  $(document).ready(function(){
  //we create a wrapping div with class 'autorefresh' around the block div for the autoupdate function.
  $( "#block-mediastream-radioplayer-streaming-data" ).wrap( '<div class="autorefresh"></div>' );
  setInterval("Drupal.mediastream_radioplayer.autoupdate()", 20000); //20s de refresh
  });
  
  /**
  * Helper functions used mediastream_radioplayer.
  */
  Drupal.mediastream_radioplayer = {

    autoupdate: function(){
    $.ajax(
    {
      type: "POST",
      url: Drupal.settings.basePath + "mediastream_radioplayer/update",
      cache: false,
      success: function(data) {
        var result = JSON.parse(data);
        $("div.autorefresh").fadeIn("slow").html(result['html']);
      }
    });
    }
  };
})(jQuery);
