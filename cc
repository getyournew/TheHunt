local function findObjectsWithinRange()
    local function isWithinRange(objectPosition, referencePosition)
        return (objectPosition - referencePosition).Magnitude <= 20
    end
    local regionSize = Vector3.new(20, 20, 20)
    local region = Region3.new(HumanoidRootPart.Position - regionSize, HumanoidRootPart.Position + regionSize)
    local partsInRegion = workspace:FindPartsInRegion3(region, nil, math.huge)
    
    for _, v in pairs(partsInRegion) do
        if v.Parent:FindFirstChild("HumanoidRootPart") and v.Parent:FindFirstChild("Humanoid") and v.Parent.Humanoid.Health ~= 0 and isWithinRange(v.Position, rootPart.Position) then
            game.ReplicatedStorage.Framework.Remotes.KnifeHitbox:FireServer(v)
        end
    end
end

findObjectsWithinRange()
