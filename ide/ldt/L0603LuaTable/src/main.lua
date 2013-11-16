T = {
	num=100,
--	sayHi=function ()
--		print("Hello Lua")
--	end,
	str="Haha"
}
-- T.num = 100

for key, var in pairs(T) do
	print("key:"..key..",var:"..var)
end