<?php

$cards = "Time:        52     94     75     94
Distance:   426   1374   1279   1216";

$strings = preg_split("/\\r\\n|\\r|\\n/", $cards);
$ans = 1;

list(, $time) = explode(":", $strings[0]);
$time = preg_split('/\s+/', trim($time));
$time = implode("", $time);

list(, $distance) = explode(":", $strings[1]);
$distance = preg_split('/\s+/', trim($distance));
$distance = implode("", $distance);

/* --- Part Two --- */
// Single time and distance
$max = 0;
for ($j = 1; $j <= $time - 1; $j++) {
	if ($j*($time-$j) > intval($distance)) {
		$max++;
	}
}

echo $max . PHP_EOL;

/* --- Part One --- */
/*
// Mulitple times and sictances.
foreach ($time as $i => $t) {
	$max = 0;
	for ($j = 1; $j <= $t - 1; $j++) {
		if ($j*($t-$j) > $distance[$i]) {
			$max++;
		}
	}

	$ans *= $max;
}
echo $ans . PHP_EOL;
*/
