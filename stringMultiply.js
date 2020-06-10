let multiply = function(a,b){
	let remind = 0
	let arrToSum = []
	let otherArr = []
	let biggestLength = 0;
	let numZeros = 0
	if(b.length > a.length){
		[a,b] = [b,a]
	}


	for(let i = b.length - 1; i >= 0; i--){
		
		let subArr = []
		for(let j = a.length - 1; j >= 0; j--){
			let multiplied = parseInt(b[i]) * parseInt(a[j]) + remind
			multiplied = multiplied.toString()
			
			if(multiplied.length == 2){
				remind = parseInt(multiplied[0])
				subArr.push(multiplied[1])

			} else {
				remind = 0
				subArr.push(multiplied[0])

			}

		}

		subArr.push(remind.toString())
		
		for(let j = 0; j < numZeros; j++){
			subArr.unshift("0")
		}
	
		remind = 0
		arrToSum.push(subArr)
		numZeros ++
	}

	remind = 0
	biggestLength = arrToSum[arrToSum.length - 1].length
	for(let i = 0; i < biggestLength; i++){
		let SUM = 0
		for(let j = 0; j < arrToSum.length; j++){
			if(arrToSum[j][i]){
				SUM+= parseInt(arrToSum[j][i])
			}
		}	
		SUM += remind
		SUM = SUM.toString()
		if(SUM.length >= 2){
			remind = parseInt(SUM.slice(0,SUM.length - 1))
			otherArr.push(SUM[SUM.length - 1])
	
		} else {
			remind = 0
			otherArr.push(SUM[0])
		}
	} 
	otherArr = otherArr.reverse()

	for(let i = 0; otherArr[i] == 0; i++){
		otherArr.shift()
	}



	return otherArr.join("")

}



console.log(multiply("207","723"))


