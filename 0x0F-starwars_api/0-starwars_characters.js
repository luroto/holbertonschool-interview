#!/usr/bin/node
// program that returns the names of characters on a
// Star Wars Movie

const request = require('request');
const url = 'http://swapi-api.hbtn.io/api/films/' + process.argv[2];

const PromiseonRequest = function (url) {
  return new Promise((resolve, reject) => {
    request(url, 'utf-8', (error, response, body) => {
      if (error) {
        reject(console.log(error));
      } else {
        resolve(JSON.parse(body));
      }
    });
  });
};

async function wait () {
  const res = await PromiseonRequest(url);
  for (let i = 0; i < res.characters.length; i++) {
    const character = await PromiseonRequest(res.characters[i]);
    console.log(character.name);
  }
}

wait();
