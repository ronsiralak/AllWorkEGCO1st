import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class FourCharactersFrame extends JFrame //implements KeyListener
{
    private JLabel      contentpane;
    private MyLabel     BirdLabel, HorseLabel, targetLabel;
    // adjust frame's size as you want
    private int frameWidth = 800, frameHeight = 500;

    public FourCharactersFrame()
    {
	setTitle("Bird moves");
	setBounds(50, 50, frameWidth, frameHeight);
	setVisible(true);
	setDefaultCloseOperation( WindowConstants.EXIT_ON_CLOSE );

	// set background image by using JLabel as contentpane
	setContentPane(contentpane = new JLabel());
	MyImageIcon background = new MyImageIcon("resources/background.jpg");
	contentpane.setIcon( background.resize(frameWidth, frameHeight) );
	contentpane.setLayout( null );

	BirdLabel = new MyLabel("resources/bird.png", "resources/plane.png"); 
        BirdLabel.setMoveConditions(500, 100, true, true);
        contentpane.add(BirdLabel);
        
        HorseLabel  = new MyLabel("resources/horse.png", "resources/motorcycle.png");  
        HorseLabel.setMoveConditions(100, 200, true, false);
        contentpane.add(HorseLabel);
        
        targetLabel = BirdLabel;
	repaint();
    }

    public static void main(String[] args) 
    {
	new FourCharactersFrame();
    }	
}


class MyLabel extends JLabel //implements MouseListener
{
    private int width = 180, height = 200;      // adjust label size as you want
    private MyImageIcon   icon1, icon2;
    private int           curX, curY;
    private boolean       horizontalMove, verticalMove;

    public MyLabel(String file1, String file2)				
    { 
        icon1 = new MyImageIcon(file1).resize(width, height);
        icon2 = new MyImageIcon(file2).resize(width, height);
	setHorizontalAlignment(JLabel.CENTER);
	resetIcon();
    }
    
    public void resetIcon()      { setIcon(icon1); }
    public void switchIcon()     { setIcon(icon2); }
    
    public void setMoveConditions(int x, int y, boolean h, boolean v)
    {
        curX = x; curY = y;
	setBounds(curX, curY, width, height);
        horizontalMove = h; verticalMove = v;        
    }
    
    // add your own code
    public void moveUp()    { }
    public void moveDown()  { }
    public void moveLeft()  { }
    public void moveRight() { }
}


// auxiliary class to resize image
class MyImageIcon extends ImageIcon
{
    public MyImageIcon(String fname)  { super(fname); }
    public MyImageIcon(Image image)   { super(image); }

    public MyImageIcon resize(int width, int height)
    {
	Image oldimg = this.getImage();
	Image newimg = oldimg.getScaledInstance(width, height, java.awt.Image.SCALE_SMOOTH);
        return new MyImageIcon(newimg);
    }
};