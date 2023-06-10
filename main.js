const addon = require('./build/Release/binding');

console.log(addon.helloWorld());
console.log(addon.addNotTwo(69));
