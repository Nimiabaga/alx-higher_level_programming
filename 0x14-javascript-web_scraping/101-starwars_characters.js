#!/usr/bin/node
// Prints all characters of a Star Wars movie
const request = require('request');
const link = 'https://swapi-api.hbtn.io/api/films/';
const id = process.argv[2];

request(link + id, (x, response, body) => {
  if (x) {
    console.log(x);
  }
  const characters = JSON.parse(body).characters;
  const name = characters.map(
    lnk => new Promise((resolve, reject) => {
      request(lnk, (x, response, body) => {
        if (x) {
          reject(x);
        }
        const info = JSON.parse(body);
        resolve(info.name);
      });
    }));
  Promise.all(name)
    .then(names => console.log(names.join('\n')))
    .catch(x => console.log(x));
});
