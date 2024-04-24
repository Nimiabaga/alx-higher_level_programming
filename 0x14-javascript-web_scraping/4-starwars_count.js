#!/usr/bin/node
// Prints the num of movies where the char “Wedge Antilles” is present
const request = require('request');
const id = process.argv[2];

request(id, (x, response, body) => {
  if (x) {
    console.log(x);
  } else if (body) {
    const info = JSON.parse(body);
    const WedgeAntilles = info.results.filter(film =>
      film.characters.find(character => character.includes('/people/18/'))
    );

    console.log(WedgeAntilles.length);
  }
});
