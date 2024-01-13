main :: IO()
main = do
    print $ quickSort [-2, 10, 5, 3, 0, 6] == [-2, 0, 3, 5, 6, 10]
    print $ quickSort [-2, 10, 5, 3, 0, 6, 2] == [-2, 0, 2, 3, 5, 6, 10]

quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort lower ++ [x] ++ quickSort higher
  where
    lower = [y | y <- xs, y <= x]
    higher = [y | y <- xs, y > x]