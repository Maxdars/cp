<?php

$games = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";

$strings = preg_split("/\\r\\n|\\r|\\n/", $games);

$ans = 0;
foreach ($strings as $s) {
	list($game, $sets) = explode(":", $s);
	list(,$id) = explode(" ", $game);
	$max_blue = 0;
    $max_red = 0;
    $max_green = 0;
	$sets = explode(";", trim($sets));
	foreach ($sets as $set) {
		$balls = explode(",", trim($set));
		foreach ($balls as $ball) {
			list($number,$color) = explode(" ", trim($ball));
			if ($color === "blue") $max_blue = intval(trim($number)) > $max_blue ? intval(trim($number)) : $max_blue;
			if ($color === "red") $max_red = intval(trim($number)) > $max_red ? intval(trim($number)) : $max_red;
			if ($color === "green") $max_green = intval(trim($number)) > $max_green ? intval(trim($number)) : $max_green;
		}
	}
	
	$ans += $max_green * $max_blue * $max_red;
}

echo $ans . PHP_EOL;
