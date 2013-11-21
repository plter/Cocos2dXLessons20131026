require "AudioEngine" 

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
	print("----------------------------------------")
	print("LUA ERROR: " .. tostring(msg) .. "\n")
	print(debug.traceback())
	print("----------------------------------------")
end

local function main()
	-- avoid memory leak
	collectgarbage("setpause", 100)
	collectgarbage("setstepmul", 5000)

	---------------

	local visibleSize = CCDirector:sharedDirector():getVisibleSize()
	local origin = CCDirector:sharedDirector():getVisibleOrigin()


	-- create farm
	local function createLayerFarm()
		local layerFarm = CCLayer:create()

		--        print("Hello Lua")
		local s = CCSprite:create("dog.png")
		layerFarm:addChild(s)
		s:setPosition(200,200)



		-- handing touch events
		local touchBeginPoint = nil

		local function onTouchBegan(x, y)
			print("TouchBegan")
			return true
		end

		local function onTouchMoved(x, y)
			print("TouchMoved")
			
		end

		local function onTouchEnded(x, y)
			print("TouchEnded")
			
		end

		local function onTouch(eventType, x, y)
			if eventType == "began" then   
				return onTouchBegan(x, y)
			elseif eventType == "moved" then
				return onTouchMoved(x, y)
			else
				return onTouchEnded(x, y)
			end
		end

		layerFarm:registerScriptTouchHandler(onTouch)
		layerFarm:setTouchEnabled(true)

		return layerFarm
	end

	-- run
	local sceneGame = CCScene:create()
	sceneGame:addChild(createLayerFarm())
	CCDirector:sharedDirector():runWithScene(sceneGame)
end

xpcall(main, __G__TRACKBACK__)
