#!/usr/bin/node
// Prints all characters of a Star Wars movie
const request = require('request');
const link = 'https://swapi-api.hbtn.io/api/films/';
const id = process.argv[2];

request(link + id, (x, response, body) => {
  if (x) {
    console.log(x);
  }
  const infolink = JSON.parse(body).characters;

  infolink.forEach(element => {
    request(element, (x, response, body) => {
      if (x) {
        console.log(x);
      }
      const info = JSON.parse(body);
      console.log(info.name);
    });
  });
});
