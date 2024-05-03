const link = 'https://swapi-api.alx-tools.com/api/people/5/?format=json';

$.get(link, function (data) {
  $('DIV#character').text(data.name);
});
