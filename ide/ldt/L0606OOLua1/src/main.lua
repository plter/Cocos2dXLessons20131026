require("People")
require("Man")

local p = People_new("ZhangSan")
p:sayHi()


local m = Man_new("Lisi")
m:sayHi()

m:sayHello()