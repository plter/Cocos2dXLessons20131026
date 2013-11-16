
require("People")
require("Man")

local p = People.new("ZhangSan");
p:sayHi()

function Man.sayHello(self)
	print("Hello "..self.name)
end


local man = Man.new("Lisi")
man:sayHi()
man:sayHello()