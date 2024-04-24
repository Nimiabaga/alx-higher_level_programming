#!/usr/bin/node
// Computes the number of tasks completed by user id
const request = require('request');
const id = process.argv[2];

request(id, (x, response, body) => {
  const tots = {};

  if (x) {
    console.log(x);
  }
  const info = JSON.parse(body);
  info.forEach(element => {
    if (element.completed) {
      if (!tots[element.userId]) {
        tots[element.userId] = 0;
      }
      tots[element.userId]++;
    }
  });
  console.log(tots);
});
