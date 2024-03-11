#!/usr/bin/node

const inputNumber = parseInt(process.argv[2]);

if (!isNaN(inputNumber)) {
  console.log(`My number: ${inputNumber}`);
} else {
  console.log('Not a number');
}
