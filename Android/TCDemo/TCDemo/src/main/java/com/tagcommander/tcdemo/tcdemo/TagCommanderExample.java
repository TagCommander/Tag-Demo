package com.tagcommander.tcdemo.tcdemo;

import android.content.Context;
import android.util.Log;
import com.tagcommander.lib.TCAppVars;
import com.tagcommander.lib.TCPredefinedVariables;
import com.tagcommander.lib.TCSDKConstants;
import com.tagcommander.lib.TagCommander;
import com.tagcommander.lib.core.TCDebug;

import java.util.EnumSet;

public class TagCommanderExample
{
    private static TagCommanderExample sharedTagCommanderExample;
    private TagCommander TC;
    public String TCStartTime;

    private TagCommanderExample()
    {
    }

    public static TagCommanderExample sharedTagManager()
    {
        if (sharedTagCommanderExample == null)
        {
            sharedTagCommanderExample = new TagCommanderExample();
        }
        return sharedTagCommanderExample;
    }

    /**
     * Init the Tag Commander instance for the whole application.
     *
     * To look at the configuration file, you can check this address: view-source:cdn.tagcommander.com/mobile/912/5.xml
     *
     * @param context the application context.
     */
    public void initTagcommander(Context context)
    {
        if (TC == null)
        {
            int TC_SITE_ID = 3311; // defines this site account ID
            int TC_CONTAINER_ID = 2; // defines this container ID

            /*
             * debug is also recommended during test as it prints information
             * that helps figuring out what is working and what is not
             */
            TCDebug.setDebugLevel(Log.VERBOSE);
//            TCDebug.setDebugLevelAndOutput(Log.VERBOSE, EnumSet.of(ETCLogOutput.CONSOLE));
            TCDebug.setNotificationLog(true);

            /*
             * For the XML example used to tag this application please check:
             * view-source:http://cdn.tagcommander.com/mobile/1263/3.xml
             * it's loaded thanks to site id and container id
             */
            TC = new TagCommander(TC_SITE_ID, TC_CONTAINER_ID, context);
            TCStartTime = TCPredefinedVariables.getInstance().getData(TCSDKConstants.kTCPredefinedVariable_CurrentVisitMs);

            /*
             * forceReload is useful and recommended during the debug phase
             * it forces TagCommander to reload the XML so it's always up to date
             *
             * Of course during release it can be removed and the XML will be reloaded
             * automatically from time to time (usually every week)
             */
//            TC.forceReload();
        }
    }

    /**
     * Build a screen name in the right format for the vendor.
     */
    public static String buildPageName(String chapter, String subChapter, String page, String click)
    {
        if (chapter == null)
        {
            chapter = "";
        }

        if (subChapter == null)
        {
            subChapter = "";
        }

        if (page == null)
        {
            page = "";
        }

        if (click != null && !click.isEmpty())
        {
            click = "--" + click;
        }

        return chapter + "::" + subChapter + "::" + page + click;
    }

    /**
     * SendPageEvent is your classic send Hit event.
     * It will allow the tag with the condition #EVENT# equal to "page" to launch
     *
     * In the xml:
     * <rule name="EQUAL"><var>EVENT</var><value>'page'</value></rule>
     *
     * Sending a hit that the user arrived on the page named "pageName"
     *
     * In the xml:
     * <param name="cd">#PAGE_NAME#</param>
     *
     * What we do is that we simply tells TagCommander
     * what are the values of the desired parameters so that it can work
     *
     * Those values are automatically replaced by Tag Commander:
     * <param name="uip">#IP#</param>
     * <param name="ua">#TC_USER_AGENT#</param>
     *
     */
    public void SendPageEvent(String pageName, String restaurant, String rating)
    {
        TCAppVars appVars = new TCAppVars();

        appVars.put("#EVENT#", "screen");
        appVars.put("#PAGE_NAME#", pageName);

        if (restaurant != null && !restaurant.isEmpty())
        {
            appVars.put("#RESTAURANT_NAME#", restaurant);
        }

        if (rating != null && !rating.isEmpty())
        {
            appVars.put("#RATING#", rating);
        }

        TC.execute(appVars);
    }

    /**
     * SendEventClick is your classic click action.
     * It will allow the tag with the condition #EVENT# equal to "click" to launch
     *
     * In the xml:
     * <rule name="EQUAL"><var>EVENT</var><value>'click'</value></rule>
     *
     * Sending a click that the user arrived on the page named "pageName"
     *
     * In the xml:
     * <param name="p">#PAGE_NAME#</param>
     * <param name="clic">#CLIC_TYPE#</param>
     *
     * What we do is that we simply tells TagCommander
     * what are the values of the desired parameters so that it can work
     * Please use the values of click type in TCATParams.java
     *
     * Some values are automatically replaced by Tag Commander.
     * For example:
     * <param name="cn">#TC_LOCAL_CONNEXION#</param>
     * <param name="os">[#TC_LOCAL_SYSNAME#]-[#TC_LOCAL_SYSVERSION#]</param>
     * <param name="r">#TC_LOCAL_SCREEN#</param>
     *
     * As a general rule, if it starts by TC_ it's automatically replaced by Tag Commander's SDK.
     *
     */
    public void SendClickEvent(String pageName, String clickType)
    {
        TCAppVars appVars = new TCAppVars();
        appVars.put("#EVENT#", "click");

        appVars.put("#CLIC_TYPE#", clickType);
        appVars.put("#PAGE_NAME#", pageName);

        TC.execute(appVars);
    }
}
