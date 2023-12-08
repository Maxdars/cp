<?php

$cards = "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
Card   2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19
Card  3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83
Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36
Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11";

$strings = preg_split("/\\r\\n|\\r|\\n/", $cards);

$occ = [];
for ($i = 0; $i < count($strings); $i++) {
	$occ[$i+1] = 1;
}

$points = [];
$ans = 0;
foreach ($strings as $s) {
	// Crads and numbers
	$count = 0;
	list($card, $numbers) = explode(":", $s);
	list(,$id) = preg_split("/\s+/", $card);

	list($wins, $nums) = explode("|", trim($numbers));
	$wins = preg_split('/\s+/', trim($wins));
	$nums = preg_split('/\s+/', trim($nums));
	
	foreach ($nums as $num) {
		if (in_array($num, $wins)) $count++;
	}
	
	// Add current card points
	$points[intval($id)] = $count;

	// Check how many elements are copied
	// should add $i < count($strings) ??? last card can copy the next prevous cards
	for ($i = intval($id) + 1; $i <= intval($id) + $count; $i++) {
		$occ[$i] = $occ[$i] + $occ[intval($id)];
	}

}

foreach ($occ as $c) {
	$ans += $c;
}

echo $ans . PHP_EOL;
