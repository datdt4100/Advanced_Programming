and :: [Bool] -> Bool
and []       = True
and (x : xs) = x && Main.and xs

concat :: [[a]] -> [a]
concat []       = []
concat (x : xs) = x ++ Main.concat xs

replicate :: Int -> a -> [a]
replicate 0 _             = []
replicate 1 x             = [x]
replicate n x | n > 0     = x : Main.replicate (n - 1) x
              | otherwise = []


nth :: [a] -> Int -> a
[] `nth` _                   = error "empty list"
(x : xs) `nth` n | n == 0    = x
                 | n > 0     = xs `nth` (n - 1)
                 | otherwise = error "negative num"

myElem :: Eq a => a -> [a] -> Bool
myElem target [] = False
myElem target (element:elements) | target == element  =  True
                                 | otherwise          =  myElem target elements


merge :: Ord a => [a] -> [a] -> [a]
merge [] []                                    = []
merge [] ys                                    = ys
merge xs []                                    = xs
merge list1@(x: xs) list2@(y : ys) | x <= y    = x : merge xs list2
                                   | otherwise = y : merge list1 ys


halve :: [a] -> ([a], [a])
halve xs = splitAt (length xs `div` 2) xs

msort :: Ord a => [a] -> [a]
msort []  = []
msort [x] = [x]
msort xs  = merge (msort f) (msort s)
            where (f, s) = halve xs



