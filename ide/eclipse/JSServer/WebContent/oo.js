function People(name) {
	this.name = name;
	
	this.sayHi = function(){
		console.log("People : Hi "+this.name);
	};
}

function Man(name){
	People.call(this,name);
}
Man.prototype = new People();

var p = new People("ZhangSan");
p.sayHi();

var m = new Man("Lisi");
m.sayHi();