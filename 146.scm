(define (get-perimeter)
  (define (calc-p sides cr)
   (* sides (* cr ( * 2 (sin(/ 3.14 sides))))))
  (calc-p (read) (read)))
