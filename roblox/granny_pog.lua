while true do
    wait(.1) -- remove this if looping constantly doesn't make your game freeze
    game:GetService("ReplicatedStorage").makePoop:FireServer()
    game:GetService("ReplicatedStorage").cleanPoop:FireServer()
end
