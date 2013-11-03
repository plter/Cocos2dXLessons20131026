#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HelloWorld : public cocos2d::CCLayer,public CCTableViewDataSource,public CCTableViewDelegate
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
public://TableViewDelegate
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual void scrollViewDidScroll(CCScrollView* view){};
    virtual void scrollViewDidZoom(CCScrollView* view){};
    
    
public://DataSource
    /**
     * cell size for a given index
     *
     * @param idx the index of a cell to get a size
     * @return size of a cell at given index
     */
    virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx);
    /**
     * a cell instance at a given index
     *
     * @param idx index to search for a cell
     * @return cell found at idx
     */
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    /**
     * Returns number of cells in a given table view.
     *
     * @return number of cells
     */
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);
private://DataSource
    CCArray *dataArr;
    
    
private:
    CCTableView *tableView;
};

#endif // __HELLOWORLD_SCENE_H__
