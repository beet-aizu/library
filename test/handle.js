function getFile(url){
    return $.ajax(
	      {
		        type     : 'GET',
		        url      : url,
		        timeout  : 20000,
		        cache    : false,
	      });
}

// copied from https://iwb.jp/jquery-javascript-html-escape/
const htmlEscape = (str) => {
    if (!str) return;
    return str.replace(/[<>&"'`]/g, (match) => {
        const escape = {
            '<': '&lt;',
            '>': '&gt;',
            '&': '&amp;',
            '"': '&quot;',
            "'": '&#39;',
            '`': '&#x60;'
        };
        return escape[match];
    });
}

function format(data){
    data = htmlEscape(data);
    l = data.search("BEGIN CUT HERE") + 15;
    r = data.search(/\n[^\n]*END CUT HERE/);
    return '<pre><code>' + data.substr(l, r - l) + '</code></pre>'
}

$(document).ready(function(){
    var query = window.location.search.substring(1);
    var url = decodeURIComponent(query.split('&')[0].split('=')[1]);
    var github = 'https://github.com/beet-aizu/library/blob/master'
    $('<a>').attr({href: github + url}).html('link').appendTo('#github');
    getFile('/library' + url).done(function(data){
        $('#status').html(format(data));
    });
});
