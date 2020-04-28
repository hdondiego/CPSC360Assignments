<!DOCTYPE html>
<html>
	<!-- Hector Dondiego -->
	<head>
		<title>Calculation</title>
	</head>
	<body>
		<?php
			function sumSequence($start, $end){
				// initializing the sum of the range to 0
				$sum = 0;

				// starting the iteration from the starting number
				// ending the iteration on the ending number, but not before the number
				// the ending number is also taken into account for the sum of the range
				for ($i = $start; $i <= $end; $i++){
					// adding the current iteration to the sum of the range
					$sum += $i;
				}

				// once all of the numbers within the range are added to the sum, return the sum
				return $sum;
			}

			// Retrieves the starting number and the ending number from the client
			$start = $_POST["startNum"];
			$end = $_POST["endNum"];

			// Starting number and ending numbers are sent to the function to get the sum of the range
			$sum = sumSequence($start, $end);

			// The difference between the starting number and ending number does not also account for the starting number
			// Each subsequent iteration until the end number is reached is taken into account, when using the difference only
			// Therefore, the difference between the ending number and starting number plus 1 will help account for the starting number
			$range = ($end - $start) + 1;

			// Print message containing the length of the range and the sum of the range
			echo "The sum of " . $range . " consecutive numbers from " . $start . " to " . $end . " is " . $sum . ".";
		?>

		<!-- A Back button for the client to enter new starting and ending numbers -->
		<form action="Dondiego_Hector_ProgAssign9.html">
			<input type="submit" name="submit" value="Back">
		</form>
	</body>
</html>
