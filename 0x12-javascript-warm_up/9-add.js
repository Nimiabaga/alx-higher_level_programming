#!/usr/bin/node

// Define func 'add' that takes two param. 'a' and 'b' and returns the sum
function add(a, b) {
    // Check if 'a' and 'b' are valid integers
    if (Number.isNaN(a) || Number.isNaN(b)) {
      console.log('Invalid input. Please provide two valid integers.');
      return;
    }
  
    return a + b;
  }
  
  // Parse command-line arguments to integers
  const arg1 = Number.parseInt(process.argv[2]);
  const arg2 = Number.parseInt(process.argv[3]);
  
  // Check if arguments are provided
  if (process.argv.length < 4) {
    console.log('Usage: ./script.js <integer1> <integer2>');
  } else {
    // Call 'add' function and print the result
    console.log(add(arg1, arg2));
  }
  