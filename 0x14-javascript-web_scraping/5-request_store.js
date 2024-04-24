#!/usr/bin/node
// Gets the contents of a webpage and stores it in a file
const fs = require('fs');
const request = require('request');
const id = process.argv[2];

request.get(id).pipe(fs.createWriteStream(process.argv[3]));
