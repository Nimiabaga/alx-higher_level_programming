$(document).ready(function () {
    function translate () {
      const link = 'https://www.fourtonfish.com/hellosalut/hello/';
      const la = $('INPUT#language_code').val();
  
      $.get(`${link}?lang=${la}`, (data) => {
        $('DIV#hello').html(data.hello);
      });
    }
  
    $('INPUT#btn_translate').click(translate);
  
    $('INPUT#language_code').keypress(function (ev) {
      if (ev.which === 13) {
        translate();
      }
    });
  });
