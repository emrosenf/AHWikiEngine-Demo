var highlighter = (function()
{
	// We're using a global variable to store the number of occurrences
	var results = [];
	var idx;
	var hyphen = String.fromCharCode(173);
	var reg = new RegExp(hyphen, "g");
    var searchPhrase;
	
    // helper function, recursively searches in elements and their child nodes
	function highlightStringInElement(element,keyword, theClass) {
		if (element) {
			if (element.nodeType == 3) {        // Text node
				while (true) {
					var value = element.nodeValue;	// Search for keyword in text node
				    //var idx = value.replace(reg, "").toLowerCase().indexOf(keyword);
					var idx = value.toLowerCase().indexOf(keyword);
					if (idx < 0) break;             // not found, abort
					
					var span = document.createElement("span");
					var text = document.createTextNode(value.substr(idx,keyword.length));
					span.appendChild(text);
					span.setAttribute("class",theClass);
					text = document.createTextNode(value.substr(idx+keyword.length));
					element.deleteData(idx, value.length - idx);
					var next = element.nextSibling;
					element.parentNode.insertBefore(span, next);
					element.parentNode.insertBefore(text, next);
					element = text;
					results.push(span);
				}
			} else if (element.nodeType == 1) { // Element node
				if (element.style.display != "none" && element.nodeName.toLowerCase() != 'select') {
					for (var i=element.childNodes.length-1; i>=0; i--) {
						highlightStringInElement(element.childNodes[i],keyword, theClass);
					}
				}
			}
		}
	}

	// the main entry point to start the search
	function search(keyword) {
		removeAllHighlights();
        searchPhrase = keyword.toLowerCase()
		results = [];
		idx = -1;
		highlightStringInElement(document.body, searchPhrase, "boxHighlight");
        if (results.length > 0) {
           for (var i = results.length-1; i >= 0; i--) {
            if (findPos(results[i]) === null) {
                results.splice(i,1)
            }
           }
			highlightNext();
        }
	}
				   
	function removeAllHighlights()
	{
	   /*for (var i = 0; i < results.length; i++)
	   {
			removeHighlights(results[i]);
	   }*/
		removeHighlights(document.body);
		idx = 0;
	}

	// helper function, recursively removes the highlights in elements and their childs
	function removeHighlights(element) {
		if (element) {
			if (element.nodeType == 1) {
                var theClass = element.getAttribute("class");
				if (theClass == "highlight" || theClass == "boxHighlight") {
					var text = element.removeChild(element.firstChild);
					element.parentNode.insertBefore(text,element);
					element.parentNode.removeChild(element);
					return true;
				} else {
					var normalize = false;
					for (var i=element.childNodes.length-1; i>=0; i--) {
						if (removeHighlights(element.childNodes[i])) {
							normalize = true;
						}
					}
					if (normalize) {
						element.normalize();
					}
				}
			}
		}
		return false;
	}


   // helper function, recursively removes the highlights in elements and their childs
   function swapHighlight(element, prevClass, newClass) {
     if (element) {
       if (element.nodeType == 1) {
         var theClass = element.getAttribute("class");
         if (theClass == prevClass) {
           element.setAttribute("class", newClass);
           return true;
         } else {
           var normalize = false;
           for (var i=element.childNodes.length-1; i>=0; i--) {
             if (fillHighlight(element.childNodes[i])) {
               normalize = true;
             }
           }
           if (normalize) {
             element.normalize();
           }
        }
      }
     }
   return false;
   }

                   
	function findPos(obj) {
		var curtop = 0;
		if (obj.offsetParent) {
			do {
				curtop += obj.offsetTop;
			} while (obj = obj.offsetParent);
			return [curtop];
		}
        return null;
	}
			   
	function highlightNext() 
	{
        swapHighlight(results[results.length-1-idx], "highlight", "boxHighlight");
		if (idx + 1 >= results.length)
			idx = 0;
		else
			idx = idx + 1;
        swapHighlight(results[results.length-1-idx], "boxHighlight", "highlight");
		window.scroll(0,Math.max(0, -30+findPos(results[results.length-1-idx])[0]));  
	}
				   
   function highlightPrevious() 
   {
        swapHighlight(results[results.length-1-idx], "highlight", "boxHighlight");
		if (idx - 1 < 0)
			idx = results.length-1;
		else
			idx = idx - 1;
        swapHighlight(results[results.length-1-idx], "boxHighlight", "highlight");
		window.scroll(0,Math.max(0, -30+findPos(results[results.length-1-idx])[0]));  
   }
	
	return {
		search : search,
		numResults : function(){return results.length;},
		next : highlightNext,
		previous: highlightPrevious,
		done : removeAllHighlights,
		removeHighlights: removeHighlights
	}

})();