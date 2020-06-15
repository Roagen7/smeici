#include <ncurses.h>

class Rect {
	
	private:
		int width, height;
		bool broken = false;
	public:
		void draw(int x, int y);
		Rect(int w = 5, int h = 5){
			width = w;
			height = h;	
		}
		void setWidth(int w){
			width = w;
		}
		void setHeight(int h){
			height = h;
		}
		void kill(){
			broken = true;
		}
		bool was_broken(){
			return broken;	
		}
		int getWidth(){
			return width;
		}
		int getHeight(){
			return height;
		}

	
};



void Rect::draw(int x, int y){
	for(int i = 0; i < width; i++){
		mvprintw( y, x + i, "-" );	
		mvprintw( y + height, x + i, "-" );		
	}
	for(int i = 1; i < height; i++){
		mvprintw(y + i, x, "|");
		mvprintw(y + i, x + width - 1, "|");
	}	

}
	
void swap(int &a, int &b){
	int tCup = a;
	a = b;
	b = tCup;

}

int abs(int a){
	return a > 0 ? a : -1 * a;
}

int main(){
	

	initscr();
	
	keypad( stdscr, TRUE );

	int key, height, width, ch_y, ch_x, ball_y = 0, ball_x = 0, v_x = 1, v_y = 1;
	char ch[] = "-_____-";
	const char LIVES[] = "lives";
	int lives = 3;
	char ball[] = "0";
	int FPS, tick_count = 0;
	int NUM_ROWS = 3;
	getmaxyx( stdscr, height, width );	
	ch_x = 0;
	ch_y =  7 * height / 8;
	nodelay( stdscr, TRUE );
	noecho();
	
	FPS = width /height * 1500;
	ball_y = 3 * height / 4; 
	Rect blocks[width / 10 * NUM_ROWS];
	
	for(int i = 0; i < width/10 * NUM_ROWS; i++){
		blocks[i].setWidth(width/10);	

	}

	if( has_colors() ){
		start_color();
	}

	
	do {	
		tick_count++;

		if( ball_y > height ){
			ball_y =  height / 4;
			lives --;
			v_y *= -1;
		} else if( ball_y <  0){
			ball_y = 0;
			v_y *= -1;
		}
		if( ball_x >= width ){
			ball_x = width - 1;
			v_x *= -1;
		} else if( ball_x < 0 ){
			ball_x = 0;
			v_x *= -1;
		}
		if( abs(ball_y - ch_y) <= 1 && ball_x >= ch_x && ball_x < ch_x + sizeof( ch ) ){
			ball_y = ch_y - 2;
			v_y *= -1;
			if( ball_x <= ch_x + sizeof( ch ) / 2 ){
				v_x*= -1;
			}


		}
				
		if( tick_count % FPS == 0 ){
			ball_x += v_x;
			ball_y += v_y;
		}

		
		key = getch();
		if(key == 260){
			ch_x--;
		}
		if(key == 261){
			ch_x++;
		}
			
		if(ch_x  + sizeof( ch )> width){
			ch_x = width - sizeof( ch );
		}
		if(ch_x < 0){
			ch_x = 0;
		}


		/*
		if(key == 259){
			ch_y--;
		}
		if(key == 258){
			ch_y++;
		}
		*/
	
		

		
		werase( stdscr );
		int row = height / 9;
		int spot = 0;	
		for( int i = 0; i < width/10 * NUM_ROWS; i++ ){
			if(i % (width/10) == 0 && i != 0){
				row+= blocks[0].getHeight();
				spot = 0;
			}			
			if( ball_x >= spot && ball_x <= spot + blocks[i].getWidth() && ball_y >= row && ball_y <= row + blocks[i].getHeight() && !blocks[i].was_broken() ){
				if( ball_y == row + blocks[i].getHeight() || ball_y == row ){
					v_y *= - 1;
				} else if( ball_x == spot || ball_x == spot + blocks[i].getWidth() ){
					v_x *= -1;
				}
				

				blocks[i].kill();
				ball_y += 1;
				
			}

			
			if( !blocks[i].was_broken() ){
				blocks[i].draw(spot, row);	
			
			}
			spot += 10;
		}

	
		mvprintw( 0,0, LIVES );
	       	mvprintw( 0, sizeof( LIVES ), "%d", lives);
		mvprintw( 1, 0, "%d", height );
		mvprintw( 1, sizeof( height ), ":");
		mvprintw( 1, sizeof( height) + 1,"%d", width);
		mvprintw( ball_y, ball_x, ball );
		mvprintw( ch_y, ch_x, ch );	
		move(0,0);	
		refresh();	
		if(lives == 0){
			key = 120;
		}
	
	
	} while( key != 120 );



	endwin();

}

