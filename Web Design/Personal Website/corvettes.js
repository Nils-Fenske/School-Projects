/* 	Nils Fenske
	Personal Website
	Javascript
*/
function switchView(x) {
	if (x == 'home') {
		document.getElementById("pic-container").style.display = "block";
		document.getElementById("comment-container").style.display = "none";
		document.getElementById("about-container").style.display = "none";
	}
	else if (x == 'comment') {
		document.getElementById("pic-container").style.display = "none";
		document.getElementById("comment-container").style.display = "block";
		document.getElementById("about-container").style.display = "none";
	}
	else if (x == 'about') {
		document.getElementById("pic-container").style.display = "none";
		document.getElementById("comment-container").style.display = "none";
		document.getElementById("about-container").style.display = "block";
	}
	else if (x == 'year') {
		// document.getElementById("year-content").style.display = "block";
		// document.getElementById("color-content").style.display = "none";
	}
	else if (x == 'color') {
		// document.getElementById("year-content").style.display = "none";
		// document.getElementById("color-content").style.display = "block";
	}
}

//retrieveCorvettesFromServer();

populateCorvettes('pictures');

// function retrieveCorvettesFromServer() {
// 	var xmlhttp = new XMLHttpRequest();

// 	xmlhttp.onreadystatechange = function() {
// 		if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
// 			var returnValues = this.responseText
// 			populateCorvettes('pictures', returnValues);
// 		}
// 	}
// 	xmlhttp.open("GET", "myDB.php?do=getVettes", true);
// 	xmlhttp.send();
// }

function populateCorvettes(elementId, year, color) {
	//var listVettes = vettes;
	var element = document.getElementById(elementId);
	var newElement = "";
	for (var i = 1; i <= 109; i++) {
		newElement += "<li><img src=\"Corvette Pics\\" + i + ".jpg\">";
		// newElement += "<div id=\"details\"><p>Year</p>";
		// newElement += "<p>Color</p>";
		// newElement += "<p>Generation</p>";
		// newElement += "<p>Style</p></div></li>";
	}
	element.innerHTML = newElement;
}
