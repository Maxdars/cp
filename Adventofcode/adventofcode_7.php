<?php

$cards = "32T3K 765
T55J5 684
KK677 28
KTJJT 220
QQQJA 483";

$strings = preg_split("/\\r\\n|\\r|\\n/", $cards);

$bid_mapping = [];

$five_of_a_kind = [];
$four_of_a_kind = [];
$full_house = [];
$three_of_a_kind = [];
$two_pair = [];
$one_pair = [];
$high_card = [];

foreach ($strings as $card) {
	list($hand, $bid) = explode(" ", $card);
	$bid_mapping[$hand] = $bid;

	$occ = [];
	foreach (str_split($hand) as $char) {
		$occ[$char] = (isset($occ[$char]) ? $occ[$char] + 1 : 1);
	}

	/* Begin part two */
	// Chnage values of joker to optimal solutions
	// In each hand, look for the most occured card
	if (isset($occ["J"])) {
		if (!(count($occ) === 1)) {
			$max_occ = 0;
			$max_occ_element = "";
			foreach ($occ as $key => $oc) {
				if ($oc > $max_occ && $key != "J") {
					$max_occ_element = $key; 
					$max_occ = $oc;
				}
			}
			$occ[$max_occ_element] += $occ["J"];
			unset($occ["J"]);
		}
	}
	/* -- End part two -- */

	$count = count($occ);
	switch($count) {
		case 1:
			$five_of_a_kind[] = $hand;
			break;

		case 2:
			$full_house_flag = true;
			foreach ($occ as $val) {
				if ($val > 3) $full_house_flag = false;
			}
			if ($full_house_flag) {
				$full_house[] = $hand;
			}
			else {
				$four_of_a_kind[] = $hand;
			}
			break;

		case 3:
			$three_of_a_kind_flag = false;
			foreach ($occ as $val) {
				if ($val > 2) $three_of_a_kind_flag = true;
			}
			if ($three_of_a_kind_flag) {
				$three_of_a_kind[] = $hand;
			}
			else {
				$two_pair[] = $hand;
			}
			break;

		case 4:
			$one_pair[] = $hand;
			break;

		case 5:
			$high_card[] = $hand;
			break;
	}
}

// Sort arrays
function comp($a, $b) {
	$weight = ["A" => 13, "K" => 12, "Q" => 11, "T" => 9, "9" => 8, "8" => 7, "7" => 6, "6" => 5, "5" => 4, "4" => 3, "3" => 2, "2" => 1, "J" => 0];
	$a_arr = str_split($a);
	$b_arr = str_split($b);

	foreach ($a_arr as $i => $val) {
		if ($weight[$a_arr[$i]] < $weight[$b_arr[$i]]) {
			return 1;
		}
		elseif ($weight[$a_arr[$i]] > $weight[$b_arr[$i]]) {
			return -1;
		}
	}
	return 0;
}

usort($five_of_a_kind, "comp");
usort($four_of_a_kind, "comp");
usort($full_house, "comp");
usort($three_of_a_kind, "comp");
usort($two_pair, "comp");
usort($one_pair, "comp");
usort($high_card, "comp");

// print_r($five_of_a_kind);
// print_r($four_of_a_kind);
// print_r($full_house);
// print_r($three_of_a_kind);
// print_r($two_pair);
// print_r($one_pair);
// print_r($high_card);

$ans = 0;
$rank = count($strings);
foreach ($five_of_a_kind as $card) {$ans += $rank * $bid_mapping[$card] ; $rank--;}
foreach ($four_of_a_kind as $card) {$ans += $rank * $bid_mapping[$card] ; $rank--;}
foreach ($full_house as $card) {$ans += $rank * $bid_mapping[$card] ; $rank--;}
foreach ($three_of_a_kind as $card) {$ans += $rank * $bid_mapping[$card] ; $rank--;}
foreach ($two_pair as $card) {$ans += $rank * $bid_mapping[$card] ; $rank--;}
foreach ($one_pair as $card) {$ans += $rank * $bid_mapping[$card] ; $rank--;}
foreach ($high_card as $card) {$ans += $rank * $bid_mapping[$card] ; $rank--;}

echo $ans;
