function getFile(url){
    return $.ajax(
	      {
		        type     : 'GET',
		        url      : url,
		        timeout  : 20000,
		        cache    : false,
	      });
}

$(document).ready(function(){
    var query = window.location.search.substring(1);
    var url = decodeURIComponent(query.split('&')[0].split('=')[1]);
    getFile(url).done(function(data){
        $("#status").html(data);
    });
});
