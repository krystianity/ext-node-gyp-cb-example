var addon = require('bindings')('addon');

addon("wurst", 12, function(){
  console.log(arguments);
});