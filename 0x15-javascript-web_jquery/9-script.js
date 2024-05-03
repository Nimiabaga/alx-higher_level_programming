const link = 'https://hellosalut.stefanbohacek.dev/?lang=fr';

$.get(link, (data) => {
  $('DIV#hello').html(data.hello);
});
