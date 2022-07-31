#lang racket

(define Zero '())

(define (succ x)
 (cons x x)
 )

(define One (succ Zero))
(define Two (succ One))

