-- a = 1
-- print("Hello Lua "..1)

People = {}
People.name = "People"

People.sayHi = function(self)
	print("People say Hi")
	print(self.name)
end

function sayHi()
	print("Hello Lua")
end

People:sayHi()