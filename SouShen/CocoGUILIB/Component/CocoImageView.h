/*
 * Copyright (c) 2012 Chukong Technologies, Inc.
 *
 * http://www.sweetpome.com
 * http://tools.cocoachina.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __CocoGUI__CocoImageView__
#define __CocoGUI__CocoImageView__

#include "CocoWidget.h"
#include "UISprite.h"
#include "UIScale9Sprite.h"

namespace cs {
    class CocoImageView : public CocoWidget
    {
    public:
        CocoImageView();
        virtual ~CocoImageView();
        static CocoImageView* create();
//        static CocoImageView* create(cocos2d::CCDictionary* options);
//        static CocoImageView* createWithJson(sp::SPJsonDictionary* options);
        virtual bool init();
//        virtual bool initWithOptions(cocos2d::CCDictionary* options);
//        virtual bool initWithOptions_json(sp::SPJsonDictionary* options);
        void setTexture(const char* fileName,bool useSpriteFrame = false);
        void setTextureRect(float x,float y,float width,float height);
        virtual CRenderNode* getValidNode();
        virtual void setAnchorPoint(const cocos2d::CCPoint &pt);
        virtual bool onTouchPressed(cocos2d::CCPoint &touchPoint);
        virtual bool onTouchReleased(cocos2d::CCPoint &touchPoint);
        void doubleClickEvent();
        void checkDoubleClick(float dt);
        void setDoubleClickEnable(bool able);
        virtual void setFlipX(bool flipX);
        virtual void setFlipY(bool flipY);
        virtual void setColor(int r,int g,int b);
        virtual void setOpacity(int opcity);
        void setScale9Enable(bool able);
        void setScale9Size(float width,float height);
        void setTexturesScale9(const char* fileName, cocos2d::CCRect capInsets, bool useSpriteFrame = false);
    protected:
        int m_nViewType;
        UIElement* m_pImage;
        int m_nClickCount;
        float m_fClickTimeInterval;
        bool m_bStartCheckDoubleClick;
        bool m_touchRelease;
        bool m_bDoubleClickEnable;
        
        bool m_bScale9Enable;
    };
}

#endif /* defined(__CocoGUI__CocoImageView__) */
