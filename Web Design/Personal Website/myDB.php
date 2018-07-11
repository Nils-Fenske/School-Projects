<?php
$servername = "cssql.seattleu.edu";
$username = "fensken3300";
$password = "cs*330023";

// Create connection
$conn = new mysqli($servername, $username, $password);

// Check connection
 if ($conn->connect_error) {
     die("Connection failed: " . $conn->connect_error);
} 
echo "Connected successfully";

function getVettes() {
    $sql = SELECT * FROM corvettes;
    $vettes = $conn->query($sql)
    retrun $vettes;
}

if ($_GET['do'] === "getVettes") {
    getVettes();
}

//Close the Connection
$conn->close();
 ?>