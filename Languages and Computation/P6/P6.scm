;Nils Fenske
;P6 version 1.0

(define L1 (list 0 5 6 3 8 1 9 7 2 4))
(define L2 (list 16 18 11 13 17 14 19 10 12))

(display "List 1: ")(display L1)(newline)
(display "List 2: ")(display L2)(newline)

;given two values m & n and a list L of numbers:
;multiply each element a of L by m, if a < n
;multiply each element a of L by (m-3), if a > n
(define (skewedMultiple L m n)
  	(cond [(null? L) '()]
  		  [(< (car L) n) (cons (* (car L) m) (skewedMultiple (cdr L) m n))]
    	  [(> (car L) n) (cons (* (car L) (- m 3)) (skewedMultiple (cdr L) m n))]
      	  [else (cons (car L) (skewedMultiple (cdr L) m n))]))

(define s1 7)
(define s2 5)

(display "Skewed Multiple L1: ")(display (skewedMultiple L1 s1 s2))(newline)

;given a number p and a list L of integers:
;add p to each odd element a of L
;if empty, returns empty list
(define (skewedAddition L p)
	(cond [(null? L) '()]
		  [(odd? (car L)) (cons (+ (car L) p) (skewedAddition (cdr L) p))]
		  [else (cons (car L) (skewedAddition (cdr L) p))]))

(display "Skewed Addition L2: ")(display (skewedAddition L2 s1))(newline)

;skewed concatenation, given two lists of numbers, L1 & L2: 
;tack L1 onto the end of L2, if L1 is smaller than or equal to L2
;insert L2 into the middle of L1, if L2 is smaller than L1
;if one list is empty, will return the non-empty lsit
;if both are empty, will return empty list
(define (skewedConcat L1 L2)
	(cond [(and (null? L1) (null? L2)) '()]
		  [(and (null? L1) L2) L2]
		  [(and (null? L2) L1) L1]
		  [(> (length L1) (length L2)) 
		  		(append (getUpper L1 (length L1)) 
		  			(append L2 (getLower L1 (length L1))))]
		  [else (append L2 L1)]))

;get upper-half, given a list and length, Lst & len:
;return the upper-half of Lst
(define (getUpper Lst len)
	(cond [(null? Lst) '()]
		  [(> len 0) (cons (car Lst) (getUpper (cdr Lst) (- len 2)))]
		  [else '()])) 

;get lower-half, given a list and length, Lst & len:
;return the lower-half of Lst
(define (getLower Lst len)
	(cond [(null? Lst) '()]
		  [(> len 0) (getLower (cdr Lst) (- len 2))]
		  [else Lst])) 

(display "Skewed Concatenation of L1 & L2: ")(display (skewedConcat L1 L2))(newline)
