$(document).ready(function () {
    $('INPUT#btn_translate').click(() => {
      const link = 'https://www.fourtonfish.com/hellosalut/hello/';
      const la = $('INPUT#language_code').val();
  
      $.get(`${link}?lang=${la}`, (data) => {
        $('DIV#hello').html(data.hello);
      });
    });
  });
