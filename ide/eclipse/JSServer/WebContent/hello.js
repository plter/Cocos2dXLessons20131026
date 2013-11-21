
//var a = "Hello";
//var b = 20;
//
//console.log("Hello JS");

function trace(msg){
	if (this.console) {
		this.console.log(msg);
	}
}

function People(name){
	this.name = name;
}

People.prototype.sayHi = function(){
	trace("People say : hi "+ this.name);
};

var p = new People("ZhangSan");
p.sayHi();

function Man(name){
	People.call(this,name);
}
Man.prototype = new People();

var m = new Man("Lisi");
m.sayHi();
