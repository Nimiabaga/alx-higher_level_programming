const axios = require('axios');

// Make a GET request to a sample URL
axios.get('https://jsonplaceholder.typicode.com/posts/1')
  .then(response => {
    console.log('Response data:', response.data);
  })
  .catch(error => {
    console.error('Error:', error);
  });

