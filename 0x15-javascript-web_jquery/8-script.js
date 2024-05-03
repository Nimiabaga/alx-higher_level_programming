const link = 'https://swapi-api.alx-tools.com/api/films/?format=json';

$.get(link, (data) => {
  data.results.forEach(film => {
    $('UL#list_movies').append(`<li>${film.title}</li>`);
  });
});
