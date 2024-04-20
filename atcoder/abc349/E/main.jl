using StatsBase

m = zeros(Int, 9)
for i in 0:2
    l = map(x -> parse(Int, x), split(readline()))
    for j in 1:3 m[i * 3 + j] = l[j] end 
end

over = (d) -> begin
    for i in 1:3:7 
        if length(countmap(d[i:i+2])) == 1 return false end 
    end
    if length(unique([d[1], d[5], d[9]])) == 1 || length(unique([d[3], d[5], d[7]])) == 1
        return true
    else
        return false
    end
end

s = Set{Int}()
d = collect(1:9)

backtrack = (x) -> begin
    if length(s) == 9 return 0 end
    ans = (x == 1 ? -Int(1e10) : Int(1e10))
    for i in 1:9
        if i ∉ s
            push!(s, i)
            d[i] = x

            if !over(d)
                if x == 1
                    e = backtrack(2)
                    if abs(e) != Int(1e10)
                        e += m[i]
                    end
                    ans = max(ans, e)
                else
                    ans = min(ans, backtrack(1))
                end
            end

            d[i] = i
            delete!(s, i)
        end
    end
    return ans
end

println((backtrack(1) + Int(1e10) > (sum(m) + Int(2e10)) / 2 ? "Takahashi" : "Aoki"))