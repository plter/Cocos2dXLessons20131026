function clone(table)
	
	local ins = {}
	
	for key, var in pairs(table) do
		ins[key] = var
	end
	
	return ins
end

function copy(dist,table)
	for key, var in pairs(table) do
		dist[key] = var
	end
end