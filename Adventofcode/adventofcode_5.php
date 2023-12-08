<?php

$data = "seeds: 79 14 55 13

seed-to-soil map:
50 98 2
52 50 48

soil-to-fertilizer map:
0 15 37
37 52 2
39 0 15

fertilizer-to-water map:
49 53 8
0 11 42
42 0 7
57 7 4

water-to-light map:
88 18 7
18 25 70

light-to-temperature map:
45 77 23
81 45 19
68 64 13

temperature-to-humidity map:
0 69 1
1 0 69

humidity-to-location map:
60 56 37
56 93 4";

$strings = preg_split("/\\r\\n|\\r|\\n/", $data);
$strings = array_filter($strings, static function($item) {
	return !empty($item);
});

// Get the seed
list(,$seeds) = explode(":", $strings[0]);
$seeds = explode(" ", trim($seeds));
unset($strings[0]);


// structure of each element :
// Array of possible ranges : start_source, end_source, start_destination, range_size
$map = [
 "seed-to-soil" => [],
 "soil-to-fertilizer" => [],
 "fertilizer-to-water" => [],
 "water-to-light" => [],
 "light-to-temperature" => [],
 "temperature-to-humidity" => [],
 "humidity-to-location" => [],
];

$next_mapping = [
"seed-to-soil" => "soil-to-fertilizer",
"soil-to-fertilizer" => "fertilizer-to-water",
"fertilizer-to-water" => "water-to-light",
"water-to-light" => "light-to-temperature",
"light-to-temperature" => "temperature-to-humidity",
"temperature-to-humidity" => "humidity-to-location",
"humidity-to-location" => null,
];

$current_mapping = "";
foreach ($strings as $s) {
	$arr = explode(" ", trim($s));
	if (end($arr) === "map:") {
		$current_mapping = reset($arr);
		continue;
	}
	
	$source_start = $arr[1];
	$source_end = $arr[1] + $arr[2];
	$destination_start = $arr[0];
	$destination_end = $arr[0] + $arr[2];

	$map[$current_mapping][] = [
		$source_start, $source_end, $destination_start, $arr[2]
	];
}

function getLowestLocationNumber($map, $next_mapping, $source, $mapping) {
	$destination = $source;
	foreach ($map[$mapping] as $ranges) {
		if ($source >= $ranges[0] && $source <= $ranges[1]) {
			$destination = $ranges[2] + ($source - $ranges[0]);
			break;
		}
	}
	
	if (!isset($next_mapping[$mapping])) {
		return $destination;
	}
	$mapping = $next_mapping[$mapping];
	return getLowestLocationNumber($map, $next_mapping, $destination, $mapping);

}

// @todo: brute force doesn't work, large intervals
for ($i = 0; $i < count($seeds); $i += 2) {
	$start = $seeds[$i];
	$end =  $seeds[$i] +  $seeds[$i+1];

	for ($j = $start; $j <= $end; $j++) {
		$val = getLowestLocationNumber($map, $next_mapping, $j, "seed-to-soil");
		if (!isset($min)) {
			$min = $val;
		}
		else {
			$min = ($val < $min ? $val : $min);
		}
	}
}

echo $min . PHP_EOL;

// https://adventofcode.com/2023/day/5