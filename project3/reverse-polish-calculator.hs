import Data.List  
  
calculateRPN :: String -> Float                             -- string parameter -> float result
calculateRPN = head . foldl stackFunction [] . words        -- stack implemented with left fold function               
    where   stackFunction (x:y:ys) "*" = (x * y):ys             -- if current item is operator
            stackFunction (x:y:ys) "+" = (x + y):ys               -- [binary operator] 
            stackFunction (x:y:ys) "-" = (y - x):ys               -- (x:y:ys) x = top, y = top-1, ys = remaining stack; "*" = item
            stackFunction (x:y:ys) "/" = (y / x):ys               -- [unary operator] 
            stackFunction (x:y:ys) "^" = (y ** x):ys              -- (x:xs) x = top, xs = remaining stack; "ln" = item 
            stackFunction (x:xs) "ln" = log x:xs                  -- [n-ary operator]
            stackFunction xs "sum" = [sum xs]                     -- xs = stack, [sum xs] = sum of stack and push result on stack        
            stackFunction xs numS = read numS:xs                -- else current item is number
                                                                  -- xs = stack, numS = item, read numS:xs = read number and push on stackFunction
