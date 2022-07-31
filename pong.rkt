#lang racket
(require 2htdp/image)
(require 2htdp/universe)

(define WIDTH 1000)
(define HEIGHT 500)
(define RADIUS 10)
(define PADDLE_WIDTH 10)
(define PADDLE_HEIGHT 100)

(struct player (y points))
(struct ball (x y velx vely))
(struct state (player1 player2 ball))

(define INIT
  (state
   (player (/ HEIGHT 2) 0)
   (player (/ HEIGHT 2) 0)
   (ball (/ WIDTH 2) (/ HEIGHT 2) -5 -5)
   )
 )

(define (clamp v mi ma) (min (max v mi) ma))

(define (move s)
  (state
   (state-player1 s)
   (state-player2 s)
   (ball
    (+ (ball-velx (state-ball s)) (ball-x  (state-ball s)))
    (+ (ball-vely (state-ball s)) (ball-y  (state-ball s)))
    (ball-velx (state-ball s))
    (ball-vely (state-ball s))
    )   
   )
 )

(define (value-bounce x bound vel)
  (if (or (>= x (- bound (* 2 RADIUS))) (<= x 0))
    (* -1 vel)
    vel
  ) 
 )

(define (apply-win s)
  (cond
    ((>= (ball-x (state-ball s)) (- WIDTH (* 2 RADIUS)))
     (state
      (player (player-y (state-player1 s)) (+ 1 (player-y (state-player1 s))))
      (state-player2 s)
      (ball
       (/ WIDTH 2)
       (/ HEIGHT 2)
       (ball-velx (state-ball s))
       (ball-vely (state-ball s))
       )   
      )
     )
    ((<= (ball-x (state-ball s)) 0)
     (state
      (state-player1 s)
      (player (player-y (state-player2 s)) (+ 1 (player-y (state-player2 s))))
      (ball
       (/ WIDTH 2)
       (/ HEIGHT 2)
       (ball-velx (state-ball s))
       (ball-vely (state-ball s))
       )   
      )
   )
    (else s)
   )
  )

(define (bounce-border s)
    (state
   (state-player1 s)
   (state-player2 s)
   (ball
    (clamp (ball-x (state-ball s)) 0 WIDTH)
    (clamp (ball-y (state-ball s)) 0 HEIGHT)
    (value-bounce (ball-x (state-ball s)) WIDTH (ball-velx (state-ball s))) 
    (value-bounce (ball-y (state-ball s)) HEIGHT (ball-vely (state-ball s)))
    )   
   )
)

(define (value-bounce-paddle b p1 p2)
  (if (or
       (and (<= (ball-x b) PADDLE_WIDTH) (<= (player-y p1) (ball-y b) (+  (player-y p1) PADDLE_HEIGHT)))
       (and (>= (ball-x b) (-  WIDTH (+ (* 2 RADIUS) PADDLE_WIDTH))) (<= (player-y p2) (ball-y b) (+  (player-y p2) PADDLE_HEIGHT)))
       )
     (ball
     (ball-x b)
     (ball-y b)
     (- (ball-velx b))
     (ball-vely b)
    )
    b
  ) 
 )


(define (bounce-paddle s)
    (state
   (state-player1 s)
   (state-player2 s)
   (value-bounce-paddle (state-ball s) (state-player1 s) (state-player2 s))
   )
  )

(define (tock s)
  ((compose1 apply-win bounce-border bounce-paddle move) s)
)

(define background
  (
   underlay/xy
   (rectangle WIDTH HEIGHT "solid" "black")
   (- (/ WIDTH 2) (/ WIDTH 50)) 0
   (rectangle (/ WIDTH 50) HEIGHT "solid" "white")
   )
  )

(define pongball 
  (circle RADIUS "solid" "red")
  )

(define paddle
  (rectangle PADDLE_WIDTH PADDLE_HEIGHT "solid" "white")
 )

(define (kh s ke)
  (state
      (player
       (cond
         ((equal? ke "w")  (- (player-y (state-player1 s)) 25))
         ((equal? ke "s")  (+ (player-y (state-player1 s)) 25))
         (else  (player-y (state-player1 s)))
       )
       (player-points (state-player1 s)))
       (player
       (cond
         ((equal? ke "i")  (- (player-y (state-player2 s)) 25))
         ((equal? ke "j")  (+ (player-y (state-player2 s)) 25))
         (else  (player-y (state-player2 s)))
       )
       (player-points (state-player2 s)))
       
      (state-ball s)
  )
 )


(define (render s)
  (underlay/xy
  (underlay/xy
   (underlay/xy
    background
    (ball-x (state-ball s)) (ball-y (state-ball s))
    pongball
    )
   0 (player-y (state-player1 s))
   paddle
   )
   (- WIDTH PADDLE_WIDTH) (player-y (state-player2 s))
   paddle
  )
 )

(define ((main) y)
  (big-bang y
      (on-tick tock)
      (to-draw render)
      (on-key kh)
   )
 )

((main) INIT)




