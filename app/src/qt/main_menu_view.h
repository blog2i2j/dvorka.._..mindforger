/*
 main_menu.h     MindForger thinking notebook

 Copyright (C) 2016-2024 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef M8RUI_MAIN_MENU_H
#define M8RUI_MAIN_MENU_H

#include <QtWidgets>

#include "../../lib/src/debug.h"

#include "main_window_view.h"
#include "recent_files_menu.h"

namespace m8r {

class MainWindowView;

/**
 * @brief MindForger main window menu view.
 *
 * View creates all menu items and Qt actions while presenter
 * implements doActions() and connects them using signals/slots
 * to this view.
 */
class MainMenuView : public QObject
{
    Q_OBJECT

    MainWindowView* mainWindow;
    QMenuBar* qMenuBar;

public:
    QMenu* menuMind;
    QMenu* menuFind;
    QMenu* menuView;
    QMenu* menuNavigator;
#ifdef MF_WIP
    QMenu* menuFlashcards;
#endif
    QMenu* menuOrganizer;
    QMenu* menuOutline;
    QMenu* menuNote;
    QMenu* menuEdit;
    QMenu* menuFormat;
#ifdef MF_WIP
    QMenu* menuTools;
#endif
    QMenu* menuHelp;

#ifdef DO_MF_DEBUG
    QAction* actionMindHack;
#endif
    // menu: MindForger
    QMenu* submenuMindNew;
    QAction* actionMindNewRepository;
    QAction* actionMindNewFile;
    QMenu* submenuMindLearn;
    QAction* actionMindLearnDirectory;
    QAction* actionMindLearnRepository;
    QAction* actionMindLearnFile;
    RecentFilesMenu* submenuMindRelearn;
    QAction* actionMindRemember;
    QAction* actionMindThink;
    QAction* actionMindAutolink;
    QAction* actionMindWingman;
    QAction* actionMindTool;
    QAction* actionMindScope;
    QAction* actionMindForget;
    QAction* actionMindSnapshot;
    QMenu* submenuMindLibrary;
    QAction* actionLibraryAdd;
    QAction* actionLibrarySync;
    QAction* actionLibraryOrphans;
    QAction* actionLibraryDeprecate;
    QAction* actionMindPreferences;
    QMenu* submenuMindExport;
    QAction* actionMindExportCsv;
    QAction* actionExit;

    // menu: Find
    QAction* actionFindFts;
    QAction* actionFindOutlineByName;
    QAction* actionFindNoteByName;
    QAction* actionFindOutlineByTag;
    QAction* actionFindNoteByTag;
#ifdef MF_WIP
    QAction* actionFindDocByName;
#endif

    // menu: View
    QAction* actionViewHome;
    QAction* actionViewDecks;
    QAction* actionViewOrganizers;
    QAction* actionViewOutlines;
    QAction* actionViewOutlinesMap;
#ifdef MF_WIP
    QAction* actionViewLibraryDocs;
#endif
    QAction* actionViewTags;
    QAction* actionViewNavigator;
    QAction* actionViewDwell;
    QAction* actionViewStencils;
    QAction* actionViewCli;
    QAction* actionViewTerminal;
    QAction* actionViewRecentNotes;
    QAction* actionViewLimbo;
    QAction* actionViewDistractionFree;
    QAction* actionViewFullscreen;

    // menu: Knowledge
    QAction* actionKnowledgeWikipedia;
    QAction* actionKnowledgeArxiv;

    // menu: Organizer
    QAction* actionOrganizerNew;
    QAction* actionOrganizerEdit;
    QAction* actionOrganizerClone;
    QAction* actionOrganizerForget;
    QAction* actionOrganizerFocusPrevious;
    QAction* actionOrganizerFocusNext;
    QAction* actionOrganizerMovePrevious;
    QAction* actionOrganizerMoveNext;

    // menu: Navigator
    QAction* actionNavigatorZoomIn;
    QAction* actionNavigatorZoomOut;
    QAction* actionNavigatorEdgesStretch;
    QAction* actionNavigatorEdgesShrink;
    QAction* actionNavigatorShuffle;

    // menu: Outline
    QAction* actionOutlineNew;
    QAction* actionOutlineEdit;
    QAction* actionOutlineHome;
    QAction* actionOutlineStencil;
    QAction* actionOutlineClone;
    QAction* actionOutlineArtExamine;
    QAction* actionOutlineForget;
    QAction* actionOutlinePromote;
    QAction* actionOutlineDemote;
    QAction* actionOutlineFirst;
    QAction* actionOutlineUp;
    QAction* actionOutlineDown;
    QAction* actionOutlineLast;
    QMenu* submenuOutlineExport;
    QAction* actionOutlineHtmlExport;
    QMenu* submenuOutlineImport;
    QAction* actionOutlineTWikiImport;
    QMenu* submenuOutlineWingman;
    QAction* actionOutlineWingmanSummarize;
    QAction* actionOutlineWingmanExplain;
    QAction* actionOutlineWingmanFind;
    QAction* actionOutlineWingmanMore;

    // menu: Note
    QAction* actionNoteNew;
    QAction* actionViewHoist;
    QAction* actionNoteEdit;
    QAction* actionNoteExternalEdit;
    QAction* actionNoteSave;
    QAction* actionNoteClose;
    QAction* actionNoteForget;
    QAction* actionNotePromote;
    QAction* actionNoteDemote;
    QAction* actionNoteFirst;
    QAction* actionNoteUp;
    QAction* actionNoteDown;
    QAction* actionNoteLast;
    QAction* actionNoteRefactor;
    QAction* actionNoteStencil;
    QAction* actionNoteClone;
    QAction* actionNoteExport;
    QAction* actionNoteImport;
    QMenu* submenuNoteWingman;
    QAction* actionNoteWingmanSummarize;
    QAction* actionNoteWingmanFixGrammar;
    QAction* actionNoteWingmanRewrite;
    QAction* actionNoteWingmanMore;

    // menu: Edit
    QAction* actionEditFind;
    QAction* actionEditFindNext;
    QAction* actionEditUndo;
    QAction* actionEditRedo;
    QAction* actionEditCut;
    QAction* actionEditCopy;
    QAction* actionEditPaste;
    QAction* actionEditLiveNotePreview;
    QAction* actionEditWordWrap;
    QAction* actionEditNameDescFocusSwap;
    QAction* actionEditExtract;
    QAction* actionEditWingman;
    QAction* actionEditComplete;
    QAction* actionEditSpellCheck;
    QMenu* submenuEditWingman;
    QAction* actionEditWingmanFixGrammar;
    QAction* actionEditWingmanExplain;
    QAction* actionEditWingmanFinishText;
    QAction* actionEditWingmanRewriteText;
    QAction* actionEditWingmanMore;

    // menu: Format
    QAction* actionFormatBold;
    QAction* actionFormatItalic;
    QAction* actionFormatStrikethrough;
    QAction* actionFormatKeyboard;
    QAction* actionFormatComment;
    QAction* actionFormatMath;
    QAction* actionFormatCode;
    QAction* actionFormatCodeBlock;
    QMenu* submenuFormatMathJax;
    QMenu* submenuFormatToc;
    QAction* actionFormatTocWithoutTags;
    QAction* actionFormatTocWithTags;
    QMenu* submenuFormatLists;
    QMenu* submenuFormatBlocks;
    QMenu* submenuFormatDiagrams;
    QAction* actionFormatDiagramsFlow;
    QAction* actionFormatDiagramsSequence;
    QAction* actionFormatDiagramsClass;
    QAction* actionFormatDiagramsState;
    QAction* actionFormatDiagramsGantt;
    QAction* actionFormatDiagramsPie;
    QAction* actionFormatMathFraction;
    QAction* actionFormatMathSum;
    QAction* actionFormatMathInt;
    QAction* actionFormatMathIiint;
    QAction* actionFormatMathAlpha;
    QAction* actionFormatMathBeta;
    QAction* actionFormatMathDelta;
    QAction* actionFormatMathGama;
    QAction* actionFormatMathText;
    QAction* actionFormatMathBar;
    QAction* actionFormatMathHat;
    QAction* actionFormatMathDot;
    QAction* actionFormatMathOverrightarrow;
    QAction* actionFormatMathCup;
    QAction* actionFormatMathCap;
    QAction* actionFormatMathEmptyset;
    QAction* actionFormatMathIn;
    QAction* actionFormatMathNotin;
    QAction* actionFormatMathSqrt;
    QAction* actionFormatMathBlock;
    QAction* actionFormatDiagramBlock;
    QAction* actionFormatBlockQuote;
    QAction* actionFormatListNumber;
    QAction* actionFormatListBullet;
    QAction* actionFormatListTask;
    QAction* actionFormatListTaskItem;
    QAction* actionFormatLink;
    QAction* actionFormatImage;
    QAction* actionFormatTable;
    QAction* actionFormatHr;
    QAction* actionFormatEmojis;
    QAction* actionFormatTimestamp;

    // menu: Help
    QAction* actionHelpDocumentation;
    QAction* actionHelpWeb;

    QAction* actionHelpMarkdown;
    QAction* actionHelpMathLivePreview;
    QAction* actionHelpMathQuickReference;
    QAction* actionHelpDiagrams;

    QAction* actionHelpReportBug;
    QAction* actionHelpCheckForUpdates;
    QAction* actionHelpAboutQt;
    QAction* actionHelpAbout;

    void showModeAwareFacet(bool repositoryMode, bool mfMode);

public:
    MainMenuView(MainWindowView& mainWindow);
    MainMenuView(const MainMenuView&) = delete;
    MainMenuView(const MainMenuView&&) = delete;
    MainMenuView &operator=(const MainMenuView&) = delete;
    MainMenuView &operator=(const MainMenuView&&) = delete;
    virtual ~MainMenuView();

    void showFacetOrganizerList(bool repositoryMode=true, bool mfMode=true);
    void showFacetOrganizerView(bool repositoryMode=true, bool mfMode=true);
    void showFacetOutlinesMap(bool repositoryMode=true, bool mfMode=true);
    void showFacetOutlineList(bool repositoryMode=true, bool mfMode=true);
    void showFacetOutlineView(bool repositoryMode=true, bool mfMode=true);
    void showFacetNoteEdit(bool repositoryMode=true, bool mfMode=true);

    void showFacetMindThink();
    void showFacetMindSleep();

    void showFacetMindAutolink(bool enabled);

    void showFacetLiveNotePreview(bool enabled);

    void showFacetNavigator();

    void addRepositoryOrFileToRelearn(const QString& path);

private:
    void showAllMenuItems();

private slots:
    void slotShowCli() { emit showCli(); }

signals:
    void showCli();
};

}

#endif // M8RUI_MAIN_MENU_H
